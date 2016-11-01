# ^ Copy Resources
FileUtils.rm_rf "#{ROOT_PATH}build/resources/"
FileUtils.mkdir "#{ROOT_PATH}build/resources/"
FileUtils.cp_r Dir.glob("#{ROOT_PATH}app/resources/*"),"#{ROOT_PATH}build/resources/"

# ^ Copy Resources -> jqueries
["framework/libs/jquery.js", "framework/libs/jquery.mobile.js"].each do |file|
  FileUtils.cp_r "#{ROOT_PATH}#{file}","#{ROOT_PATH}build/resources/"
end
FileUtils.cp_r "#{ROOT_PATH}framework/libs/images","#{ROOT_PATH}build/"
# Copy Resources -> jqueries $
# Copy Resources $
