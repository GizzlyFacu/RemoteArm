project('server_project', 'cpp',
  default_options: ['cpp_std=c++20'])


boost_deps = dependency('boost', method: 'pkg-config', required: true)
spdlog_dep = dependency('spdlog', method: 'pkg-config', required: true)

# Para windou boost necesita "Ws2_32.lib" y "wsock32"
if host_machine.system() == 'windows'
  win_args = ['-lws2_32', '-lwsock32']
else
  win_args = []
endif

executable('armserver',
  'src/main.cpp',
  dependencies: [boost_deps,spdlog_dep],link_args: win_args)
