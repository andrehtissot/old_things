#!/usr/local/bin/ruby

ARGV.each do |arg|
  case arg
    when '-v' || '--verbose'
      VERBOSE = true
    when '--debug'
      DEBUG_MODE = true
    when /--default-actions=(all|none)/
      NO_ACTION = (arg.match(/--default-actions=(all|none)/)[1] == 'none')
    when /--mount-html=(yes|no)/
      MOUNT_HTML = (arg.match(/--mount-html=(yes|no)/)[1] == 'yes')
    when /--mount-js=(yes|no)/
      MOUNT_JS = (arg.match(/--mount-js=(yes|no)/)[1] == 'yes')
    when /--mount-css=(yes|no)/
      MOUNT_CSS = (arg.match(/--mount-css=(yes|no)/)[1] == 'yes')
    when /--compact-html=(yes|no)/
      COMPACT_HTML = (arg.match(/--compact-html=(yes|no)/)[1] == 'yes')
    when /--compact-js=(yes|no)/
      COMPACT_JS = (arg.match(/--compact-js=(yes|no)/)[1] == 'yes')
    when /--compact-css=(yes|no)/
      COMPACT_CSS = (arg.match(/--compact-css=(yes|no)/)[1] == 'yes')
    when /--handle-resources=(yes|no)/
      HANDLE_RESOURCES = (arg.match(/--handle-resources=(yes|no)/)[1] == 'yes')
    when /--compress-images=(yes|no)/
      COMPRESS_IMAGES = (arg.match(/--compress-images=(yes|no)/)[1] == 'yes')
    when /--embody-images=(yes|no)/
      EMBODY_IMAGES = (arg.match(/--embody-images=(yes|no)/)[1] == 'yes')
  end
end

NO_ACTION  ||= false
DEBUG_MODE ||= false
VERBOSE    ||= false

['HANDLE_RESOURCES'].each do |const|
  unless(Object.const_defined?(const))
    Object.const_set(const, !NO_ACTION)
  end
end

['COMPACT_HTML', 'COMPACT_JS', 'COMPACT_CSS', 'COMPRESS_IMAGES', 'EMBODY_IMAGES'].each do |const|
  unless(Object.const_defined?(const))
    Object.const_set(const, !(NO_ACTION || DEBUG_MODE))
  end
end

[[COMPACT_HTML,'MOUNT_HTML'], [COMPACT_JS,'MOUNT_JS'], [COMPACT_CSS,'MOUNT_CSS']].each do |const|
  unless(Object.const_defined?(const[1]))
    Object.const_set(const[1], (const[0] || !NO_ACTION))
  end
end



ROOT_PATH = File.expand_path("#{File.expand_path(File.dirname(__FILE__))}/../../") + '/'

print 'Starting the boostrap...' if VERBOSE
if COMPACT_HTML || COMPACT_CSS || COMPACT_JS || EMBODY_IMAGES
  require "#{ROOT_PATH}framework/scripts/mount/mount.bootstrap.rb"
else
  require "#{ROOT_PATH}framework/scripts/mount/dont_compact/mount.bootstrap.rb"
end
puts 'ok' if VERBOSE


if MOUNT_HTML
  print 'Mounting HTML...' if VERBOSE
  require "#{ROOT_PATH}framework/scripts/mount/mount.mount_html.rb"
  puts 'ok' if VERBOSE
end

if MOUNT_JS
  if DEBUG_MODE
    print 'Mounting Javascript on DEBUG_MODE...' if VERBOSE
    require "#{ROOT_PATH}framework/scripts/mount/debug/mount.mount_javascript_for_debug.rb"
  elsif COMPACT_JS
    print 'Mounting and Compacting Javascript...' if VERBOSE
    require "#{ROOT_PATH}framework/scripts/mount/mount.mount_javascript.rb"
  else
    print 'Mounting Javascript...' if VERBOSE
    require "#{ROOT_PATH}framework/scripts/mount/dont_compact/mount.mount_javascript.rb"
  end
  puts 'ok' if VERBOSE
end

if MOUNT_CSS
  if COMPACT_CSS
    print 'Mounting and Compacting CSS...' if VERBOSE
    require "#{ROOT_PATH}framework/scripts/mount/mount.mount_css.rb"
  else
    print 'Mounting CSS...' if VERBOSE
    require "#{ROOT_PATH}framework/scripts/mount/dont_compact/mount.mount_css.rb"
  end
  puts 'ok' if VERBOSE
end

if HANDLE_RESOURCES
  print 'Handling resources...' if VERBOSE
  if DEBUG_MODE
    require "#{ROOT_PATH}framework/scripts/mount/debug/mount.handle_resources_for_debug.rb"
  else
    require "#{ROOT_PATH}framework/scripts/mount/mount.handle_resources.rb"
  end
  puts 'ok' if VERBOSE
end

if COMPACT_HTML
  print 'Compacting HTML...' if VERBOSE
  require "#{ROOT_PATH}framework/scripts/mount/mount.compact_html.rb"
  puts 'ok' if VERBOSE
end

if COMPRESS_IMAGES
  print 'Compressing Images...' if VERBOSE
  require "#{ROOT_PATH}framework/scripts/mount/mount.compact_images.rb"
  puts 'ok' if VERBOSE
end

if EMBODY_IMAGES
  print 'Emboding Images...' if VERBOSE
  require "#{ROOT_PATH}framework/scripts/mount/mount.embody_images.rb"
  puts 'ok' if VERBOSE
end

