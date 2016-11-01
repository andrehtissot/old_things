unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

require "#{ROOT_PATH}framework/scripts/libs/file_ext.rb"

def return_join_files(file_out, *files_in)
  file_out = File.new file_out, 'w+'
  
  files_in.each do |file_in|
    file_in = File.open "#{ROOT_PATH}#{file_in}", 'r+'
    
    file_in.each do |line|
      file_out.printb line
    end
    
    file_in.close
  end

  file_out.printb :force => true
  file_out.close
end
