defmodule Cairo.Pattern do
  @type type ::
          :pattern_solid
          | :pattern_surface
          | :pattern_linear
          | :pattern_radial
          | :pattern_mesh
          | :pattern_raster

  @type extend ::
          :extend_none
          | :extend_repeat
          | :extend_reflect
          | :extend_pad

  @type filter ::
          :filter_fast
          | :filter_good
          | :filter_best
          | :filter_nearest
          | :filter_bilinear
          | :filter_gaussian
end
