{
	'variables': {
		'rm'               : '<!(node -e "require(\'addon-tools-raub\').rm()")',
		'cp'               : '<!(node -e "require(\'addon-tools-raub\').cp()")',
		'mkdir'            : '<!(node -e "require(\'addon-tools-raub\').mkdir()")',
		'binary'           : '<!(node -e "require(\'addon-tools-raub\').bin()")',
		'labsound_include' : '<!(node -e "require(\'deps-labsound-raub\').include()")',
		'labsound_bin'     : '<!(node -e "require(\'deps-labsound-raub\').bin()")',
	},
	'targets': [
		{
			'target_name': 'webaudio',
			'sources': [
				'cpp/bindings.cpp',
				# 'cpp/analyser-node.cpp',
				'cpp/audio-buffer.cpp',
				'cpp/audio-buffer-source-node.cpp',
				'cpp/audio-context.cpp',
				'cpp/audio-destination-node.cpp',
				'cpp/audio-listener.cpp',
				'cpp/audio-node.cpp',
				'cpp/audio-param.cpp',
				# 'cpp/audio-processing-event.cpp',
				'cpp/audio-scheduled-source-node.cpp',
				# 'cpp/audio-timestamp.cpp',
				# 'cpp/audio-worklet.cpp',
				# 'cpp/audio-worklet-global-scope.cpp',
				# 'cpp/audio-worklet-node.cpp',
				# 'cpp/audio-worklet-processor.cpp',
				'cpp/base-audio-context.cpp',
				'cpp/biquad-filter-node.cpp',
				# 'cpp/channel-merger-node.cpp',
				# 'cpp/channel-splitter-node.cpp',
				# 'cpp/constant-source-node.cpp',
				'cpp/convolver-node.cpp',
				'cpp/delay-node.cpp',
				# 'cpp/dynamics-compressor-node.cpp',
				'cpp/gain-node.cpp',
				# 'cpp/iir-filter-node.cpp',
				# 'cpp/media-element-audio-source-node.cpp',
				# 'cpp/media-stream-audio-destination-node.cpp',
				# 'cpp/media-stream-audio-source-node.cpp',
				# 'cpp/offline-audio-completion-event.cpp',
				# 'cpp/offline-audio-context.cpp',
				'cpp/oscillator-node.cpp',
				'cpp/panner-node.cpp',
				# 'cpp/periodic-wave.cpp',
				# 'cpp/script-processor-node.cpp',
				# 'cpp/stereo-panner-node.cpp',
				# 'cpp/wave-shaper-node.cpp',
			],
			'include_dirs': [
				'<!@(node -e "require(\'addon-tools-raub\').include()")',
				'<(labsound_include)',
			],
			'library_dirs': [ '<(labsound_bin)' ],
			'libraries'    : [ '-llabsound' ],
			'conditions'   : [
				[
					'OS=="linux"', {
						'libraries': [
							'-Wl,-rpath,<(labsound_bin)',
						],
					}
				],
				[
					'OS=="mac"', {
						'libraries': [
							'-Wl,-rpath,<(labsound_bin)',
						],
					}
				],
				[
					'OS=="win"',
					{
						'libraries' : [ '-lwinmm', '-lole32', '-luser32', '-lgdi32' ],
						'msvs_settings' : {
							'VCCLCompilerTool' : {
								'AdditionalOptions' : [
									'/O2','/GL','/Gm-', '/Fm-','/EHsc'
								]
							},
							'VCLinkerTool' : {
								'AdditionalOptions' : ['/RELEASE','/OPT:REF','/OPT:ICF','/LTCG']
							},
						},
					},
				],
			],
		},
		{
			'target_name'  : 'make_directory',
			'type'         : 'none',
			'dependencies' : ['webaudio'],
			'actions'      : [{
				'action_name' : 'Directory created.',
				'inputs'      : [],
				'outputs'     : ['build'],
				'action': ['<(mkdir)', '-p', '<(binary)']
			}],
		},
		{
			'target_name'  : 'copy_binary',
			'type'         : 'none',
			'dependencies' : ['make_directory'],
			'actions'      : [{
				'action_name' : 'Module copied.',
				'inputs'      : [],
				'outputs'     : ['binary'],
				'action'      : ['<(cp)', 'build/Release/webaudio.node', '<(binary)/webaudio.node'],
			}],
		},
		# {
		# 	'target_name'  : 'remove_extras',
		# 	'type'         : 'none',
		# 	'dependencies' : ['copy_binary'],
		# 	'actions'      : [{
		# 		'action_name' : 'Build intermediates removed.',
		# 		'inputs'      : [],
		# 		'outputs'     : ['cpp'],
		# 		'conditions'  : [
		# 			[ 'OS=="linux"', { 'action' : [
		# 				'rm',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/webaudio.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio.node',
		# 				'<(module_root_dir)/build/Release/webaudio.node'
		# 			] } ],
		# 			[ 'OS=="mac"', { 'action' : [
		# 				'rm',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/bindings.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/analyser-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-buffer.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-buffer-source-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-context.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-destination-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-listener.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-param.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-processing-event.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-scheduled-source-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-timestamp.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-worklet-global-scope.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-worklet-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/audio-worklet-processor.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/base-audio-context.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/biquad-filter-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/channel-merger-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/channel-splitter-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/constant-source-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/convolver-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/delay-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/dynamics-compressor-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/gain-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/iir-filter-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/media-element-audio-source-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/media-stream-audio-destination-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/media-stream-audio-source-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/offline-audio-completion-event.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/offline-audio-context.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/oscillator-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/panner-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/periodic-wave.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/script-processor-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/stereo-panner-node.o',
		# 				'<(module_root_dir)/build/Release/obj.target/webaudio/cpp/wave-shaper-node.o',
		# 				'<(module_root_dir)/build/Release/webaudio.node'
		# 			] } ],
		# 			[ 'OS=="win"', { 'action' : [
		# 				'<(rm)',
		# 				'<(module_root_dir)/build/Release/webaudio.*',
		# 				'<(module_root_dir)/build/Release/obj/webaudio/*.*'
		# 			] } ],
		# 		],
		# 	}],
		# },
	]
}
