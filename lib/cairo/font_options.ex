defmodule Cairo.FontOptions do
  @type subpixel_order ::
          :subpixel_default
          | :subpixel_rgb
          | :subpixel_bgr
          | :subpixel_vrgb
          | :subpixel_vbgr

  @type hint_style ::
          :hint_default
          | :hint_none
          | :hint_slight
          | :hint_medium
          | :hint_full

  @type hint_metrics ::
          :metrics_default
          | :metrics_off
          | :metrics_on
end
