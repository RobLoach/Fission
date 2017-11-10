project(
	'Fission',
	'cpp',
	default_options: [
		'cpp_std=c++1z',
		'warning_level=3'
	], version: '0.1.0',
	license : 'BSD3'
)

pkg = import('pkgconfig')
incdir = include_directories('./ext/vulkan-hpp/vulkan', './ext/nuklear', './src/include', '.')
cc = meson.get_compiler('cpp')
doxygen   = find_program('doxygen', required: false)
cfg = configuration_data()

# Build Options
gfxbackend = get_option('gfxbackend')
gendocs = get_option('gendocs')

# API documentation generation
if doxygen.found() and gendocs
	dot = find_program('dot', required: false)
	latex = find_program('latex', required: false)

	doxydat = configuration_data()

	doxydat.set('PROJECT_NAME', meson.project_name())
	doxydat.set('PROJECT_VERSION', meson.project_version())
	doxydat.set('PROJECT_SRC', meson.current_source_dir())
	# If we have dot, we will generate class diagrams
	if dot.found()
		doxydat.set('USE_DOT', 'YES')
		doxydat.set('DOT', dot.path())
	endif

	if latex.found()
		doxydat.set('USE_LATEX', 'YES')
		doxydat.set('LATEX', latex.path())
	endif

	doxyfile = configure_file(
		input: './etc/Doxyfile.in',
		output: 'Doxyfile',
		configuration: doxydat,
		install: false
	)

	custom_target(
		'doc',
		input: doxyfile,
		output: [ 'html', 'latex', ],
		command: [ doxygen, doxyfile ],
		install: false,
		build_by_default: true
	)

endif

cfg.set('FISSION_VERSION', meson.project_version())
cfg.set('FISSION_BACKEND', gfxbackend)
cfg.set('COMPILER_NAME', cc.get_id())
cfg.set('COMPILER_VERSION', cc.version())


deps = []

srcs = [
	'./src/Fission.cc', './src/nuklear.cc', './src/FissionWindow.cc', './src/Logger.cc'
]

headers = [
	'./ext/nuklear/nuklear.h', './src/include/Fission.hh', './src/include/FissionWindow.hh',
	'./src/include/Backend/GenericBackend.hh', './src/include/Utility/Event.hh',
	'./src/include/Utility/Singleton.hh', './src/include/Utility/Strutil.hh',

	# Widgets
	'./src/include/Widgets/BaseWidget.hh'

	]



if gfxbackend == 'X11GL3'
	message('X11 OpenGL3 backend selected')

	deps += [
		cc.find_library('m', required : true),
		dependency('xcb', version : '>=1.10', required : true),
		cc.find_library('GL', required : true),
		cc.find_library('GLU', required : true)
	]

	srcs += [
		'./src/X11GL3Backend.cc',
	]

	headers += [
		'./src/include/Backend/X11GL3Backend.hh'
	]

	cfg.set10('__X11GL3', true)

elif gfxbackend == 'X11VULKAN'
	message('X11 Vulkan backend selected')

	deps += [
		cc.find_library('m', required : true),
		dependency('xcb', version : '>=1.10', required : true),
		cc.find_library('vulkan', required : true)
	]

	srcs += [
		'./src/X11VULKANBackend.cc',
	]

	headers += [
		'./src/include/Backend/X11VULKANBackend.hh',
		'./ext/vulkan-hpp/vulkan/vulkan.hpp'
	]

	cfg.set10('__X11VULKAN', true)

elif gfxbackend == 'WAYGL3'
	message('Waylan OpenGL3 backend selected')

	deps += [
		cc.find_library('m', required : true),
		dependency('wayland-client', version : '>=1.4', required : true),
		cc.find_library('GL', required : true),
		cc.find_library('GLU', required : true)
	]

	srcs += [
		'./src/WAYGL3Backend.cc',
	]

	headers += [
		'./src/include/Backend/WAYGL3Backend.hh'
	]

	cfg.set10('__WAYGL3', true)

elif gfxbackend == 'WAYVULKAN'
	message('Wayland Vulkan backend selected')

	deps += [
		cc.find_library('m', required : true),
		dependency('wayland-client', version : '>=1.4', required : true),
		cc.find_library('vulkan', required : true)
	]

	srcs += [
		'./src/WAYVULKANBackend.cc',
	]

	headers += [
		'./src/include/Backend/WAYVULKANBackend.hh',
		'./ext/vulkan-hpp/vulkan/vulkan.hpp'
	]

	cfg.set10('__WAYVULKAN', true)

else
	error('Unknown rendering backend \'' + gfxbackend + '\'. ')
endif


fcfg = configure_file(
	input: './etc/FissionConfig.hh.in',
	output: 'FissionConfig.hh',
	configuration: cfg
)

headers += fcfg


fission = shared_library(
	'fission-@0@'.format(gfxbackend),
	srcs,
	include_directories: incdir,
	dependencies: deps,
	version: meson.project_version(),
	soversion: '0',
	install : true)

executable('fission-demo',
	[ './demo/fission-demo.cc' ],
	link_with: [ fission ] ,
	include_directories: incdir,
	dependencies: deps,
	install: false
)

pkg.generate(
	name: 'fission',
	description: 'A C++-ish wrapper for nuklear',
	url: 'https://github.com/xampp/fission',
	version: meson.project_version(),
	filebase: 'libfission',
	libraries: [ fission ],
	subdirs: [ '.' ]
)


install_headers(headers, subdir: 'fission')