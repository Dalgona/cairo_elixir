defmodule Cairo.Pango do
  @type wrap_mode ::
          :wrap_word
          | :wrap_char
          | :wrap_word_char

  @type ellipsize_mode ::
          :ellipsize_none
          | :ellipsize_start
          | :ellipsize_middle
          | :ellipsize_end

  @type alignment ::
          :align_left
          | :align_center
          | :align_right
end
