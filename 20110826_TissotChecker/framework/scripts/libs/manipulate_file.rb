unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

require "#{ROOT_PATH}framework/scripts/libs/file_ext.rb"

def prepend file_in, what, where, file_out, options = {}
  file_in  = File.open "#{ROOT_PATH}#{file_in}", 'r+'
  file_out = File.new "#{ROOT_PATH}#{file_out}", 'w+'

  max_occurencies = options[:max]
  count_occurencies = 1 if max_occurencies
  
  replace_mode = options[:replace_mode]

  count = 1
  stash = ''
  searching = where.split('')
  while char = file_in.getc
    if searching[count-1] == char
      if count < searching.size
        if char == searching[count-1]
          count += 1
          stash << char
        else
          file_out.printb "#{stash}#{char}"
          count = 1
          stash = ''
        end
      else
        file_out.printb (replace_mode ? what : "#{what}#{stash}")
        if(max_occurencies && max_occurencies < (count_occurencies+=1))
          file_out.printb "#{char}" unless replace_mode
          while char = file_in.getc
            file_out.printb char
          end
        end
        stash = ''
        count = 1
      end
    else
      count = 1
      file_out.printb "#{stash}#{char}"
      stash = ''
    end
  end
  file_in.close
  file_out.printb :force => true
  file_out.close
end

def prepend1 file, what, where, options = {}
  prepend file, what, where, "#{file}.tmp", options
  FileUtils.rm "#{ROOT_PATH}#{file}"
  FileUtils.mv "#{ROOT_PATH}#{file}.tmp","#{ROOT_PATH}#{file}"
end

def prepend2 file_in, file_src, where, file_out, options = {}
  file_in  = File.new "#{ROOT_PATH}#{file_in}", 'r+'
  file_out = File.new "#{ROOT_PATH}#{file_out}", 'w+'
  file_src = File.new "#{ROOT_PATH}#{file_src}", 'r+'

  text_before = options[:text_before] || ''
  text_after = options[:text_after] || ''
  count = 1
  stash = ''
  searching = where.split('')

  while char = file_in.getc
    if searching[count-1] == char
      if count < searching.size
        if char == searching[count-1]
          count += 1
          stash << char
        else
          count = 1
          file_out.printb "#{stash}#{char}"
          stash = ''
        end
      else
        file_out.printb text_before
        while schar = file_src.getc
          file_out.printb schar
        end
        file_out.printb text_after
        file_src.rewind
        file_out.printb "#{stash}#{char}"
        stash = ''
        count = 1
      end
    else
      count = 1
      file_out.printb "#{stash}#{char}"
      stash = ''
    end
  end

  file_in.close
  file_out.printb :force => true
  file_out.close
  file_src.close
end

def prepend3 file, file_src, where, options = {}
  prepend2 file, file_src, where, "#{file}.tmp", options
  FileUtils.rm "#{ROOT_PATH}#{file}"
  FileUtils.mv "#{ROOT_PATH}#{file}.tmp","#{ROOT_PATH}#{file}"
end

def append file_in, what, where, file_out, options = {}
  file_in  = File.new "#{ROOT_PATH}#{file_in}", 'r+'
  file_out = File.new "#{ROOT_PATH}#{file_out}", 'w+'

  max_occurencies = options[:max]
  count_occurencies = 1 if max_occurencies
  
  skip_occurencies = options[:skip]
  skipped_occurencies = 1 if skip_occurencies

  count = 0
  stash = ''
  searching = where.split('')
  searching_size = searching.size

  while char = file_in.getc
    if searching[count] == char
      count+=1
      file_out.printb char
      if count == searching_size
        if(!skip_occurencies || skip_occurencies < (skipped_occurencies+=1))
          file_out.printb what
          if(max_occurencies && max_occurencies < (count_occurencies+=1))
            while char = file_in.getc
              file_out.printb char
            end
          end
        end
      end
    else
      count = 0
      file_out.printb char
    end
  end
  file_in.close
  file_out.printb :force => true
  file_out.close
end

def append1 file, what, where, options = {}
  append file, what, where, "#{file}.tmp", options
  FileUtils.rm "#{ROOT_PATH}#{file}"
  FileUtils.mv "#{ROOT_PATH}#{file}.tmp","#{ROOT_PATH}#{file}"
end

def append_at_end_of_file file_in, what, options = {}
  file_out = options[:output]
  
  if file_out
    FileUtils.cp "#{ROOT_PATH}#{file_in}","#{ROOT_PATH}#{file_out}", :force => true
  else
    file_out = file_in
  end

  file_out = File.new "#{ROOT_PATH}#{file_out}", 'a'

  file_out.printb (options[:text_before] || '')
  file_out.printb what
  file_out.printb (options[:text_after] || ''), :force => true

  file_out.close
end

def append_at_end_of_file2 file_in, file_src, options = {}
  file_out = options[:output]

  if file_out
    FileUtils.cp "#{ROOT_PATH}#{file_in}","#{ROOT_PATH}#{file_out}", :force => true
  else
    file_out = file_in
  end

  file_out = File.new "#{ROOT_PATH}#{file_out}", 'a'
  file_src = File.new "#{ROOT_PATH}#{file_src}", 'r+'

  file_out.printb (options[:text_before] || '')
  while char = file_src.getc
    file_out.printb char
  end
  file_out.printb (options[:text_after] || ''), :force => true

  file_out.close
  file_src.close
end

def replace1 file, what, where, options = {}
  file_out = (options[:output] ? options[:output] : "#{file}.tmp")
  options[:replace_mode] = true
  prepend file, what, where, file_out, options
  unless options[:output]
    FileUtils.rm "#{ROOT_PATH}#{file}"
    FileUtils.mv "#{ROOT_PATH}#{file}.tmp","#{ROOT_PATH}#{file}"
  end
end
