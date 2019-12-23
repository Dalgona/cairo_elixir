defmodule Cairo.Surface do
  defstruct [
    :handle,
    :status,
    :content_type,
    :device_offset,
    :device_scale,
    :fallback_resolution,
    :type,
    :backend_info
  ]

  @type t :: %__MODULE__{
          handle: term(),
          status: Cairo.status(),
          content_type: content_type(),
          device_offset: Cairo.vec2(),
          device_scale: Cairo.vec2(),
          fallback_resolution: Cairo.vec2(),
          type: type(),
          backend_info: term()
        }

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
