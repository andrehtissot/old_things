unless Object.const_defined? 'ROOT_PATH'
  puts "You need to define ROOT_PATH!\nExiting..."; exit
end

require "#{ROOT_PATH}framework/scripts/libs/file_ext.rb"

def return_who_has_this_string dir, files, matching_string
  files = [files] if files.is_a? String
  if files.is_a? Array
    files.collect! do |file_name|
      file = File.open "#{ROOT_PATH}#{dir}#{file_name}", 'r+'
      count = 0
      searching = matching_string.split('')
      searching_size = searching.size-2

      while char = file.getc
        if searching[count] == char
          if count == searching_size
            return file_name
          else
            count+=1
          end
        else
          count = 0
        end
      end
    end
    files.compact
  else
    puts "What are you doing?\nThe files argument for return_only_those_who_matches must be a array or string"; exit
  end
end

def return_who_matches dir, files, regex
  files = [files] if files.is_a? String
  if files.is_a? Array
    files = files.collect do |file_name|
      if File.too_big?("#{ROOT_PATH}#{dir}#{file_name}")
        puts "The #{file_name} is too big to open in this method, sorry"; exit
      end

      text = IO.read "#{ROOT_PATH}#{dir}#{file_name}"

      if text.match regex
        file_name
      else
        nil
      end
    end
    files.compact
  else
    puts "What are you doing?\nThe files argument for return_only_those_who_matches must be a array or string"; exit
  end
end

