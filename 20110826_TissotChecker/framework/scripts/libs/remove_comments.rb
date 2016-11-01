unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

require "#{ROOT_PATH}framework/scripts/libs/file_ext.rb"

#You can you like remove_comment_html [file_in, file_out],[file_in2, file_out2]
#              or remove_comment_html file, file2
#         or even remove_comment_html [file_in, file_out], file2
def remove_comment_css(*files_in_and_out)
  files_in_and_out.each do |file_in_and_out|
    if file_in_and_out.is_a? String
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out}.tmp", 'w+'
    else
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out[0]}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out[1]}", 'w+'
    end

    last_char = ''
    while current_char = file_in.getc
      if last_char == '/' && current_char == '*'
        while((char = file_in.getc) && !((char == '/') && (last_char == '*')))
          last_char = char
        end
        current_char = ''
      else
        file_out.printb last_char
      end
      last_char = current_char
    end
    file_out.printb "#{last_char}\n", :force => true

    file_in.close
    file_out.close

    if file_in_and_out.is_a? String
      FileUtils.rm "#{ROOT_PATH}#{file_in_and_out}"
      FileUtils.mv "#{ROOT_PATH}#{file_in_and_out}.tmp","#{ROOT_PATH}#{file_in_and_out}"
    end
  end
end

#You can you like remove_comment_html [file_in, file_out],[file_in2, file_out2]
#              or remove_comment_html file, file2
#         or even remove_comment_html [file_in, file_out], file2
def remove_comment_html(*files_in_and_out)
  files_in_and_out.each do |file_in_and_out|
    if file_in_and_out.is_a? String
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out}.tmp", 'w+'
    else
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out[0]}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out[1]}", 'w+'
    end

    stored_chars = ''
    while current_char = file_in.getc
      if current_char == '<'
        file_out.printb stored_chars
        stored_chars = current_char
      elsif current_char == '!' && stored_chars == '<'
        stored_chars << current_char
      elsif current_char == '-' && stored_chars == '<!'
        stored_chars << current_char
      elsif current_char == '-' && stored_chars == '<!-'
        stored_chars = ['','']
        while comment_char = file_in.getc
          if comment_char == '>' && stored_chars == ['-','-']
            break
          end
          stored_chars.shift
          stored_chars.push comment_char
        end
        stored_chars = ''
      else
        file_out.printb "#{stored_chars}#{current_char}"
        stored_chars = ''
      end
    end
    file_out.printb "#{stored_chars}\n", :force => true

    file_in.close
    file_out.close
    
    if file_in_and_out.is_a? String
      FileUtils.rm "#{ROOT_PATH}#{file_in_and_out}"
      FileUtils.mv "#{ROOT_PATH}#{file_in_and_out}.tmp","#{ROOT_PATH}#{file_in_and_out}"
    end
  end
end

#You can you like remove_comment_html [file_in, file_out],[file_in2, file_out2]
#              or remove_comment_html file, file2
#         or even remove_comment_html [file_in, file_out], file2
def remove_comment_js(*files_in_and_out)
  files_in_and_out.each do |file_in_and_out|
    if file_in_and_out.is_a? String
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out}.tmp", 'w+'
    else
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out[0]}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out[1]}", 'w+'
    end

    last_char = ''
    lastest_char = ''
    
    while current_char = file_in.getc
      if (current_char == "\"") || (current_char == "\'")
        file_out.printb "#{last_char}#{current_char}"
        while((char = file_in.getc) && !((char == current_char) && (last_char != '\\')))
          file_out.printb char
          last_char = char 
        end
      else
        if last_char == '/'
          if lastest_char == '\\'
            file_out.printb last_char 
            last_char = ''
          else
            if current_char == '/'
              while((char = file_in.getc) && (char != "\n")); end
              current_char = "\n"
            elsif current_char == '*'
              while current_char = file_in.getc
                if current_char == '/' && last_char == '*' 
                  current_char = ''
                  break
                end
                last_char = current_char
              end
            else
              if lastest_char != '/'
                file_out.printb last_char
              end
            end
          end
        else
          file_out.printb last_char
          if lastest_char == '\\' && last_char == '\\'
      	    last_char = ''
          end
        end
      end
      lastest_char = last_char
      last_char = current_char
    end
    file_out.printb "#{last_char}\n", :force => true
    file_out.close
    file_in.close

    if file_in_and_out.is_a? String
      FileUtils.rm "#{ROOT_PATH}#{file_in_and_out}"
      FileUtils.mv "#{ROOT_PATH}#{file_in_and_out}.tmp","#{ROOT_PATH}#{file_in_and_out}"
    end
  end
end
