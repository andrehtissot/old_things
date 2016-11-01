# ^ Removing older css's
FileUtils.rm Dir.glob("#{ROOT_PATH}build/*.css")
# Removing older css's $

# ^ Mount CSS file
FileUtils.cp "#{ROOT_PATH}framework/libs/jquery.mobile.css","#{ROOT_PATH}build/index.css"
append_at_end_of_file2 "build/index.css", "app/views/application/application.css" rescue nil
# Mount CSS file $

