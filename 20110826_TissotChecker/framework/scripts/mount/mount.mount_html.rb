# ^ Removing older htm's
FileUtils.rm_f Dir.glob("#{ROOT_PATH}build/*.htm")
# Removing older htm's $

# ^ Mount HTML file
FileUtils.cp "#{ROOT_PATH}app/views/application/application.htm","#{ROOT_PATH}build/index.htm"

get_views_names.each do |view|

# ^ Mount HTML file -> Views
  prepend3 "build/index.htm", "app/views/#{view}/#{view}.htm", '</body>', :text_before => "<div data-role=\"page\" id=\"#{view}\">", :text_after => '</div>'
# Mount HTML file -> Views $

# ^ Mount HTML file -> Subviews
  get_subviews_for(view).each do |subview|
    prepend3 "build/index.htm", "app/views/#{view}/#{subview}/#{subview}.htm", '</body>', :text_before => "<div data-role=\"page\" id=\"#{view}&#{subview}\">", :text_after => '</div>'
  end
# Mount HTML file -> Subviews $
end
# Mount HTML file $
