pngs = get_files_recursively("build/resources/", /\.png$/i)
pngs.each do |png|
  system "optipng #{ROOT_PATH}build/resources/#{png} -o 4 -quiet"
end

jpgs = get_files_recursively("build/resources/", /\.jpe?g$/i)
jpgs.each do |jpg|
  system "jpegoptim --quiet #{ROOT_PATH}build/resources/#{jpg} > /dev/null"
end
