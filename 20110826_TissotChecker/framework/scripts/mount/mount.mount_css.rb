# ^ Removing older css's
FileUtils.rm Dir.glob("#{ROOT_PATH}build/*.css")
# Removing older css's $

# ^ Mount CSS file
FileUtils.cp "#{ROOT_PATH}framework/libs/jquery.mobile.css", "#{ROOT_PATH}build/index.css"
remove_comment_css "build/index.css"

FileUtils.cp "#{ROOT_PATH}app/views/application/application.css", "#{ROOT_PATH}build/application.css.tmp"
remove_comment_css "build/application.css.tmp"
minify_css "build/application.css.tmp"

append_at_end_of_file2 "build/index.css", "build/application.css.tmp"

FileUtils.rm "#{ROOT_PATH}build/application.css.tmp"
# Mount CSS file $

