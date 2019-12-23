defmodule Cairo.Surface.ImageSurfaceInfo do
  defstruct [:format, :width, :height, :stride]

  @type t :: %__MODULE__{
          format: Cairo.format(),
          width: integer(),
          height: integer(),
          stride: integer()
        }
end
