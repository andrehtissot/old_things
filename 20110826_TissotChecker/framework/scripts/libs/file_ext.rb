class File
  MAX_BUFFER_SIZE = 2000000
  attr_accessor :buffered_text

  def printb(text, options = {})
    if text.is_a? Hash
      options = text
    else
      if @buffered_text.nil?
        @buffered_text = text.clone
      else
        @buffered_text << text
      end
    end
    if @buffered_text.size > File::MAX_BUFFER_SIZE || options[:force]
      print @buffered_text
      @buffered_text = ''
    end
  end
  
  def self.too_big? file_path
    File.size(file_path) > File::MAX_BUFFER_SIZE
  end
end
