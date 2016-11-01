unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

def get_files_recursively(dir, matching_regex = /./, subdir = nil)
  files_found = []
  subdir = "#{subdir}/" if subdir

  files = Dir.new("#{ROOT_PATH}#{dir}#{subdir}").to_a
  files.delete '.'
  files.delete '..'
  files.each do |file|
    if File.directory?("#{ROOT_PATH}#{dir}#{subdir}#{file}")
      files_found += get_files_recursively dir, matching_regex, "#{subdir}#{file}"
    elsif file.match(matching_regex) && File.file?("#{ROOT_PATH}#{dir}#{subdir}#{file}")
      if File.size("#{ROOT_PATH}#{dir}#{subdir}#{file}") > 0
        files_found << "#{subdir}#{file}"
      end
    end
  end
  files_found
end

