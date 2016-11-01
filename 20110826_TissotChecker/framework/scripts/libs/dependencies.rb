unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

def get_dependecies(file)
  dependencies = []
  file = File.open "#{ROOT_PATH}#{file}", 'r+'

  file.each do |line|
    if /\/\/\!@/ =~ line
      dependencies = dependencies | line[4..line.length].split(',').collect {|dep| dep.chomp.strip}
    end
  end

  file.close
  dependencies
end
