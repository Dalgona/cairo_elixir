defmodule Cairo.Path do
  alias Cairo.Context
  alias Cairo.NativeFunctions, as: NF

  @spec new_path(Context.t()) :: Context.t()
  def new_path(context) do
    NF.new_path(context.handle)
    refresh_current_point(context)
  end

  @spec new_sub_path(Context.t()) :: Context.t()
  def new_sub_path(context) do
    NF.new_sub_path(context.handle)
    refresh_current_point(context)
  end

  @spec close_path(Context.t()) :: Context.t()
  def close_path(context) do
    NF.close_path(context.handle)
    refresh_current_point(context)
  end

  @spec arc(Context.t(), Cairo.vec2(), number(), number(), number()) :: Context.t()
  def arc(context, center, radius, angle1, angle2) do
    NF.arc(context.handle, center, radius, angle1, angle2)
    refresh_current_point(context)
  end

  @spec arc_negative(Context.t(), Cairo.vec2(), number(), number(), number()) :: Context.t()
  def arc_negative(context, center, radius, angle1, angle2) do
    NF.arc_negative(context.handle, center, radius, angle1, angle2)
    refresh_current_point(context)
  end

  @spec curve_to(Context.t(), Cairo.vec2(), Cairo.vec2(), Cairo.vec2()) :: Context.t()
  def curve_to(context, pt1, pt2, pt3) do
    NF.curve_to(context.handle, pt1, pt2, pt3)
    refresh_current_point(context)
  end

  @spec line_to(Context.t(), Cairo.vec2()) :: Context.t()
  def line_to(context, pt) do
    NF.line_to(context.handle, pt)
    refresh_current_point(context)
  end

  @spec move_to(Context.t(), Cairo.vec2()) :: Context.t()
  def move_to(context, pt) do
    NF.move_to(context.handle, pt)
    refresh_current_point(context)
  end

  @spec rectangle(Context.t(), Cairo.vec2(), Cairo.vec2()) :: Context.t()
  def rectangle(context, {x, y}, {width, height}) do
    NF.rectangle(context.handle, x, y, width, height)
    refresh_current_point(context)
  end

  @spec rel_curve_to(Context.t(), Cairo.vec2(), Cairo.vec2(), Cairo.vec2()) :: Context.t()
  def rel_curve_to(context, pt1, pt2, pt3) do
    NF.rel_curve_to(context.handle, pt1, pt2, pt3)
    refresh_current_point(context)
  end

  @spec rel_line_to(Context.t(), Cairo.vec2()) :: Context.t()
  def rel_line_to(context, pt) do
    NF.rel_line_to(context.handle, pt)
    refresh_current_point(context)
  end

  @spec rel_move_to(Context.t(), Cairo.vec2()) :: Context.t()
  def rel_move_to(context, pt) do
    NF.rel_move_to(context.handle, pt)
    refresh_current_point(context)
  end

  @spec path_extents(Context.t()) :: {Cairo.vec2(), Cairo.vec2()}
  def path_extents(context) do
    NF.path_extents(context.handle)
  end

  @spec refresh_current_point(NF.cairo_handle()) :: Context.t()
  defp refresh_current_point(%Context{handle: handle} = context) do
    Context.refresh_status(%Context{context | current_point: do_refresh_current_point(handle)})
  end

  @spec do_refresh_current_point(NF.cairo_handle()) :: Cairo.vec2() | nil
  defp do_refresh_current_point(handle) do
    if NF.has_current_point(handle), do: NF.get_current_point(handle)
  end
end
