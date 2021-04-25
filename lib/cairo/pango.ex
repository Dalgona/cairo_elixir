defmodule Cairo.Pango do
  alias Cairo.Context
  alias Cairo.NativeFunctions, as: NF

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

  @type layout_options :: [
          font: binary(),
          width: number(),
          height: number() | [{:lines, integer()}],
          indent: number(),
          line_spacing: number(),
          justify: boolean(),
          alignment: :left | :center | :right,
          wrap: :word | :char | :word_char,
          ellipsize: :none | :start | :middle | :end,
          single_paragraph: boolean()
        ]

  @spec layout_path(Context.t(), binary(), layout_options()) :: Context.t()
  def layout_path(cr, markup, options \\ []) when is_binary(markup) and is_list(options) do
    h_layout = setup_layout(cr, markup, options)

    NF.pc_layout_path(cr.handle, h_layout)
    Context.refresh(cr)
  end

  @spec show_layout(Context.t(), binary(), layout_options()) :: Context.t()
  def show_layout(cr, markup, options \\ []) when is_binary(markup) and is_list(options) do
    h_layout = setup_layout(cr, markup, options)

    NF.pc_show_layout(cr.handle, h_layout)
    Context.refresh(cr)
  end

  @spec setup_layout(Context.t(), binary(), layout_options()) :: NF.pango_layout_handle()
  defp setup_layout(cr, markup, options) do
    options = if(Keyword.keyword?(options), do: options, else: [])
    h_layout = NF.pc_create_layout(cr.handle)

    options
    |> Enum.uniq_by(&elem(&1, 0))
    |> Enum.map(&process_option/1)
    |> Enum.reject(&is_nil/1)
    |> Enum.each(& &1.(h_layout))

    NF.pango_layout_set_markup(h_layout, markup)

    h_layout
  end

  @spec process_option({atom(), term()}) :: (NF.pango_layout_handle() -> term())
  defp process_option(option)

  defp process_option({:font, font}) when is_binary(font) do
    fn layout ->
      font_desc = NF.pango_font_desc_from_string(font)
      NF.pango_layout_set_font_description(layout, font_desc)
    end
  end

  defp process_option({:width, width}) when is_number(width) and width >= 0 do
    &NF.pango_layout_set_width(&1, width)
  end

  defp process_option({:height, {:line, lines}}) when is_integer(lines) and lines > 0 do
    &NF.pango_layout_set_height_pu(&1, -lines)
  end

  defp process_option({:height, height}) when is_number(height) and height >= 0 do
    &NF.pango_layout_set_height(&1, height)
  end

  defp process_option({:indent, indent}) when is_number(indent) do
    &NF.pango_layout_set_indent(&1, indent)
  end

  defp process_option({:line_spacing, factor}) when is_number(factor) do
    &NF.pango_layout_set_line_spacing(&1, factor)
  end

  defp process_option({:justify, justify}) do
    &NF.pango_layout_set_justify(&1, !!justify)
  end

  defp process_option({:alignment, align}) when align in ~w(left center right)a do
    &NF.pango_layout_set_alignment(&1, :"align_#{align}")
  end

  defp process_option({:wrap, wrap}) when wrap in ~w(word char word_char)a do
    &NF.pango_layout_set_wrap(&1, :"wrap_#{wrap}")
  end

  defp process_option({:ellipsize, ellipsize}) when ellipsize in ~w(none start middle end)a do
    &NF.pango_layout_set_ellipsize(&1, :"ellipsize_#{ellipsize}")
  end

  defp process_option({:single_paragraph, setting}) do
    &NF.pango_layout_set_single_paragraph_mode(&1, !!setting)
  end

  defp process_option(_), do: nil
end
