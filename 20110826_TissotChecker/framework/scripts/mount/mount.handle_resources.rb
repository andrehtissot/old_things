# ^ Copy Resources
FileUtils.rm_rf "#{ROOT_PATH}build/resources/"
FileUtils.mkdir "#{ROOT_PATH}build/resources/"
FileUtils.cp_r Dir.glob("#{ROOT_PATH}app/resources/*"),"#{ROOT_PATH}build/resources/"

# ^ Copy Resources -> jqueries
FileUtils.cp_r "#{ROOT_PATH}framework/libs/images","#{ROOT_PATH}build/"
# Copy Resources -> jqueries $
# Copy Resources $
