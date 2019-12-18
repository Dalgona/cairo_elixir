defmodule Cairo.Surface do
  @type content_type :: :color | :alpha | :color_alpha

  @type type ::
          :image
          | :pdf
          | :ps
          | :xlib
          | :xcb
          | :glitz
          | :quartz
          | :win32
          | :beos
          | :directfb
          | :svg
          | :os2
          | :win32_printing
          | :quartz_image
          | :script
          | :qt
          | :recording
          | :vg
          | :gl
          | :drm
          | :tee
          | :xml
          | :skia
          | :subsurface
          | :cogl
end
