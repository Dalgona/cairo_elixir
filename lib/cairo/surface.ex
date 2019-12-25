defmodule Cairo.Surface do
  alias Cairo.NativeFunctions, as: NF
  alias Cairo.Surface.ImageSurfaceInfo

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

  #
  # CONSTRUCTORS
  #

  @spec create_similar(t(), content_type(), integer(), integer()) :: t()
  def create_similar(surface, content, width, height) do
    handle = NF.surface_create_similar(surface.handle, content, width, height)

    refresh(%__MODULE__{handle: handle})
  end

  @spec create_similar_image(t(), Cairo.format(), integer(), integer()) :: t()
  def create_similar_image(surface, format, width, height) do
    handle = NF.surface_create_similar_image(surface.handle, format, width, height)

    refresh(%__MODULE__{handle: handle})
  end

  #
  # BACKEND-SPECIFIC CONSTRUCTORS
  #

  @spec create_image(Cairo.format(), integer(), integer()) :: t()
  def create_image(format, width, height) do
    handle = NF.image_surface_create(format, width, height)

    refresh(%__MODULE__{handle: handle})
  end

  #
  # OTHER FUNCTIONS
  #

  @spec finish(t()) :: t()
  def finish(%__MODULE__{handle: handle} = surface) do
    NF.surface_finish(handle)

    surface
  end

  @spec flush(t()) :: t()
  def flush(%__MODULE__{handle: handle} = surface) do
    NF.surface_flush(handle)

    surface
  end

  @spec mark_dirty(t()) :: t()
  def mark_dirty(%__MODULE__{handle: handle} = surface) do
    NF.surface_mark_dirty(handle)

    surface
  end

  @spec mark_dirty_rectangle(t(), Cairo.point(), Cairo.vec2()) :: t()
  def mark_dirty_rectangle(surface, {x, y}, {width, height}) do
    NF.surface_mark_dirty_rectangle(surface.handle, x, y, width, height)

    surface
  end

  @spec set_device_offset(t(), Cairo.vec2()) :: t()
  def set_device_offset(surface, {x_off, y_off} = offset) do
    NF.surface_set_device_offset(surface.handle, x_off, y_off)

    %__MODULE__{surface | device_offset: offset}
  end

  @spec set_device_scale(t(), Cairo.vec2()) :: t()
  def set_device_scale(surface, {x_scale, y_scale} = scale) do
    NF.surface_set_device_scale(surface.handle, x_scale, y_scale)

    %__MODULE__{surface | device_scale: scale}
  end

  @spec set_fallback_resolution(t(), Cairo.vec2()) :: t()
  def set_fallback_resolution(surface, {x_ppi, y_ppi} = resolution) do
    NF.surface_set_fallback_resolution(surface.handle, x_ppi, y_ppi)

    %__MODULE__{surface | fallback_resolution: resolution}
  end

  @spec refresh(t()) :: t()
  def refresh(%__MODULE__{handle: handle} = surface) do
    type = NF.surface_get_type(handle)

    %__MODULE__{
      surface
      | status: NF.surface_status(handle),
        content_type: NF.surface_get_content(handle),
        device_offset: NF.surface_get_device_offset(handle),
        device_scale: NF.surface_get_device_scale(handle),
        fallback_resolution: NF.surface_get_fallback_resolution(handle),
        type: type,
        backend_info: refresh_backend_info(handle, type)
    }
  end

  @spec refresh_backend_info(term(), type()) :: term()
  defp refresh_backend_info(handle, type)

  defp refresh_backend_info(handle, :image) do
    %ImageSurfaceInfo{
      format: NF.image_surface_get_format(handle),
      width: NF.image_surface_get_width(handle),
      height: NF.image_surface_get_height(handle),
      stride: NF.image_surface_get_stride(handle)
    }
  end
end
