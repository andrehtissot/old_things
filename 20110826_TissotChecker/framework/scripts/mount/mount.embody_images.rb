#Look for all images declared
declared_images = []
['index.htm','index.css','index.js'].each do |file|
  unless File.too_big?("#{ROOT_PATH}build/#{file}")
    text = IO.read "#{ROOT_PATH}build/#{file}"
    text.scan(/([\w\-_\/]*\.(jpe?g|png))/i) do |match|
      declared_images << [file, match[0]]
    end
  end
end

#Here we'll decide if the image must be embodied
while image_array = declared_images.pop
  #First we check if the image file exist
  file  = image_array[0]
  image = image_array[1]
  if File.file? "#{ROOT_PATH}build/#{image}"
    if declared_images.include? image_array
      #If the image is used more than one time, just forget it
      declared_images.delete image_array
    elsif !File.too_big?("#{ROOT_PATH}build/#{image}")
      image64 = Base64.encode64(IO.read("#{ROOT_PATH}build/#{image}")).delete("\n")
      
      if image.match /\.jpe?g$/i
        replace1 "build/#{file}", "data:image/jpeg;base64,#{image64}",image, {:max => 1}
      elsif image.match /\.png$/i
        replace1 "build/#{file}", "data:image/png;base64,#{image64}", image, {:max => 1}
      #else
        #is unknown type
      end
      FileUtils.rm "#{ROOT_PATH}build/#{image}"
    end
  end
end
