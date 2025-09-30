project(
	'simulación_u2',
	'java',
	version: '1.0.0',
	meson_version: '>=1.8.0',

	license: 'LICENSE.txt'
)

# **********************
# *** Subdirectories ***
# **********************

subdir('src')

# *****************
# *** All files ***
# *****************

java_files = main_sources

# *****************
# *** Build jar ***
# *****************

simulacion = jar(
	'simulacion_u2',
	java_files,
	main_class: 'Main'
)

# ******************
# *** Run target ***
# ******************

run_target(
	'run',
	command: [
		'java', '-jar', 'simulacion_u2.jar'
	]
)