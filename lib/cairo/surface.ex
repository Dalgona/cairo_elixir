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
          handle: NF.surface_handle(),
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

  @spec create_image_from_png(binary()) :: t()
  def create_image_from_png(png_data) do
    handle = NF.image_surface_create_from_png(png_data)

    refresh(%__MODULE__{handle: handle})
  end

  @spec create_image_from_png_file(Path.t()) :: t()
  def create_image_from_png_file(path) do
    path |> File.read!() |> create_image_from_png()
  end

  #
  # OTHER FUNCTIONS
  #

  @spec finish(t()) :: t()
  def finish(surface) do
    NF.surface_finish(surface.handle)
    refresh_status(surface)
  end

  @spec flush(t()) :: t()
  def flush(surface) do
    NF.surface_flush(surface.handle)
    refresh_status(surface)
  end

  @spec mark_dirty(t()) :: t()
  def mark_dirty(surface) do
    NF.surface_mark_dirty(surface.handle)
    refresh_status(surface)
  end

  @spec mark_dirty_rectangle(t(), Cairo.point(), Cairo.vec2()) :: t()
  def mark_dirty_rectangle(surface, {x, y}, {width, height}) do
    NF.surface_mark_dirty_rectangle(surface.handle, x, y, width, height)
    refresh_status(surface)
  end

  @spec set_device_offset(t(), Cairo.vec2()) :: t()
  def set_device_offset(surface, offset) do
    NF.surface_set_device_offset(surface.handle, offset)
    refresh_status(%__MODULE__{surface | device_offset: offset})
  end

  @spec set_device_scale(t(), Cairo.vec2()) :: t()
  def set_device_scale(surface, scale) do
    NF.surface_set_device_scale(surface.handle, scale)
    refresh_status(%__MODULE__{surface | device_scale: scale})
  end

  @spec set_fallback_resolution(t(), Cairo.vec2()) :: t()
  def set_fallback_resolution(surface, resolution) do
    NF.surface_set_fallback_resolution(surface.handle, resolution)
    refresh_status(%__MODULE__{surface | fallback_resolution: resolution})
  end

  @spec write_png(t()) :: {:ok, iodata()} | {:error, Cairo.status()}
  def write_png(%__MODULE__{handle: handle}) do
    NF.surface_write_to_png(handle)
  end

  @spec refresh(%__MODULE__{handle: NF.surface_handle()}) :: t()
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

  @spec refresh_status(%__MODULE__{handle: NF.surface_handle()}) :: t()
  def refresh_status(%__MODULE__{handle: handle} = surface) do
    %__MODULE__{surface | status: NF.surface_status(handle)}
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
