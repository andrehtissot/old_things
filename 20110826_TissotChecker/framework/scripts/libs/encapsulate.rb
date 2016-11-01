unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

require "#{ROOT_PATH}framework/scripts/libs/file_ext.rb"

def encapsulate_css_in_js(*files_in_and_out)
  files_in_and_out.each do |file_in_and_out|
    file_in = File.open "#{ROOT_PATH}#{file_in_and_out[0]}", 'r+'
    file_out = File.new "#{ROOT_PATH}#{file_in_and_out[1]}", 'w+'

    while current_char = file_in.getc
      case current_char
        when "\n"
          #nothing
        when "\\"
          file_out.printb '\\\\'
        when "\""
          file_out.printb '\\"'
        else
          file_out.printb current_char
      end
    end
    file_out.printb :force => true

    file_in.close
    file_out.close
  end
end

def encapsulate_css_in_js2 file_in, file_out
  encapsulate_css_in_js [file_in, file_out]
end
