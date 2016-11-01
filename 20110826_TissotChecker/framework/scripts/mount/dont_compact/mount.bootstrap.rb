require 'find'
require 'fileutils'

require "#{ROOT_PATH}framework/scripts/libs/manipulate_file.rb"
require "#{ROOT_PATH}framework/scripts/libs/encapsulate.rb"
require "#{ROOT_PATH}framework/scripts/libs/string_ext.rb"
require "#{ROOT_PATH}framework/scripts/libs/searching.rb"
require "#{ROOT_PATH}framework/scripts/libs/filter_files.rb"
require "#{ROOT_PATH}framework/scripts/mount/mount.methods.rb"

FileUtils.mkdir "#{ROOT_PATH}build" unless File.directory?("#{ROOT_PATH}build")
