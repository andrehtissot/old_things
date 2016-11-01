unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

require "#{ROOT_PATH}framework/scripts/libs/file_ext.rb"

#Can use like "minify_html [file_in, file_out],[file_in2, file_out2]"
#          or "minify_html  file_in, file_out"
def minify_html(*files_in_and_out)
  files_in_and_out.each do |file_in_and_out|
    if file_in_and_out.is_a? String
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out}.tmp", 'w+'
    else
      file_in = File.open "#{ROOT_PATH}#{file_in_and_out[0]}", 'r+'
      file_out = File.new "#{ROOT_PATH}#{file_in_and_out[1]}", 'w+'
    end

    last_char = ''
    last_char_was_space = false
    last_char_was_breakline = false
    while current_char = file_in.getc
      if current_char == "\n"
        last_char_was_breakline = true
      end
      if current_char == ' '
        last_char_was_space = true
      elsif (["\n",' ',"\t"].include?(current_char) && ["\n",' ',"\t"].include?(last_char))
        last_char_was_space = false
      elsif !["\n","\t"].include?(current_char)
        file_out.printb (last_char_was_space && !last_char_was_breakline) ? " #{current_char}" : current_char
        last_char_was_space = false
        last_char_was_breakline = false
      end
      last_char = current_char
    end
    file_out.printb :force => true

    file_in.close
    file_out.close
    
    if file_in_and_out.is_a? String
      FileUtils.rm "#{ROOT_PATH}#{file_in_and_out}"
      FileUtils.mv "#{ROOT_PATH}#{file_in_and_out}.tmp","#{ROOT_PATH}#{file_in_and_out}"
    end
  end
end

#Can use like "minify_css [file_in, file_out],[file_in2, file_out2]"
#          or "minify_css  file_in, file_out"
def minify_css(*files_in_and_out)
  files_in_and_out.each do |file_in_and_out|
    if file_in_and_out.is_a? String
      file_in  = "#{ROOT_PATH}#{file_in_and_out}"
      file_out = "#{ROOT_PATH}#{file_in_and_out}.tmp"
    else
      file_in  = "#{ROOT_PATH}#{file_in_and_out[0]}"
      file_out = "#{ROOT_PATH}#{file_in_and_out[1]}"
    end

    system "java -jar #{ROOT_PATH}framework/scripts/libs/yuicompressor-2.4.6.jar --type css #{file_in} -o #{file_out}"

    if file_in_and_out.is_a? String
      FileUtils.rm file_in
      FileUtils.mv file_out, file_in
    end 
  end
end

#Can use like "minify_js [file_in, file_out],[file_in2, file_out2]"
#          or "minify_js  file_in, file_out"
def minify_js(*files_in_and_out)
  files_in_and_out.each do |file_in_and_out|
    if file_in_and_out.is_a? String
      file_in  = "#{ROOT_PATH}#{file_in_and_out}"
      file_out = "#{ROOT_PATH}#{file_in_and_out}.tmp"
    else
      file_in  = "#{ROOT_PATH}#{file_in_and_out[0]}"
      file_out = "#{ROOT_PATH}#{file_in_and_out[1]}"
    end

    system "java -jar #{ROOT_PATH}framework/scripts/libs/yuicompressor-2.4.6.jar --type js #{file_in} -o #{file_out}"

    if file_in_and_out.is_a? String
      FileUtils.rm file_in
      FileUtils.mv file_out, file_in
    end 
  end
end
