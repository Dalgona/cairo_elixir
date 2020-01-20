defmodule Cairo.Context do
  alias Cairo.NativeFunctions, as: NF
  alias Cairo.Surface

  defstruct [
    :handle,
    :target,
    :status,
    :antialias,
    :dash,
    :fill_rule,
    :line_cap,
    :line_join,
    :line_width,
    :miter_limit,
    :tolerance
  ]

  @type t :: %__MODULE__{
          handle: NF.cairo_handle(),
          target: Surface.t(),
          status: Cairo.status(),
          antialias: Cairo.antialias(),
          dash: {[number()], number()},
          fill_rule: Cairo.fill_rule(),
          line_cap: Cairo.line_cap(),
          line_join: Cairo.line_join(),
          line_width: number(),
          miter_limit: number(),
          tolerance: number()
        }

  #
  # Constructor
  #

  @spec create(Surface.t()) :: t()
  def create(%Surface{handle: surface_handle} = surface) do
    handle = NF.create(surface_handle)

    refresh(%__MODULE__{handle: handle, target: surface})
  end

  @spec save(t()) :: t()
  def save(context) do
    NF.save(context.handle)
    refresh_status(context)
  end

  @spec restore(t()) :: t()
  def restore(context) do
    NF.save(context.handle)
    refresh_status(context)
  end

  @spec set_source_rgb(t(), number(), number(), number()) :: t()
  def set_source_rgb(context, red, green, blue) do
    NF.set_source_rgb(context.handle, red, green, blue)
    refresh_status(context)
  end

  @spec set_source_rgba(t(), number(), number(), number(), number()) :: t()
  def set_source_rgba(context, red, green, blue, alpha) do
    NF.set_source_rgba(context.handle, red, green, blue, alpha)
    refresh_status(context)
  end

  @spec set_antialias(t(), Cairo.antialias()) :: t()
  def set_antialias(context, antialias) do
    NF.set_antialias(context.handle, antialias)
    refresh_status(%__MODULE__{context | antialias: antialias})
  end

  @spec set_dash(t(), [number()], number()) :: t()
  def set_dash(context, dashes, offset) do
    NF.set_dash(context.handle, dashes, offset)
    refresh_status(%__MODULE__{context | dash: {dashes, offset}})
  end

  @spec set_fill_rule(t(), Cairo.fill_rule()) :: t()
  def set_fill_rule(context, fill_rule) do
    NF.set_fill_rule(context.handle, fill_rule)
    refresh_status(%__MODULE__{context | fill_rule: fill_rule})
  end

  @spec set_line_cap(t(), Cairo.line_cap()) :: t()
  def set_line_cap(context, line_cap) do
    NF.set_line_cap(context.handle, line_cap)
    refresh_status(%__MODULE__{context | line_cap: line_cap})
  end

  @spec set_line_join(t(), Cairo.line_join()) :: t()
  def set_line_join(context, line_join) do
    NF.set_line_join(context.handle, line_join)
    refresh_status(%__MODULE__{context | line_join: line_join})
  end

  @spec set_line_width(t(), number()) :: t()
  def set_line_width(context, width) do
    NF.set_line_width(context.handle, width)
    refresh_status(%__MODULE__{context | line_width: width})
  end

  @spec set_miter_limit(t(), number()) :: t()
  def set_miter_limit(context, limit) do
    NF.set_miter_limit(context, limit)
    refresh_status(%__MODULE__{context | miter_limit: limit})
  end

  @spec set_tolerance(t(), number()) :: t()
  def set_tolerance(context, tolerance) do
    NF.set_tolerance(context.handle, tolerance)
    refresh_status(%__MODULE__{context | tolerance: tolerance})
  end

  @spec clip(t()) :: t()
  def clip(context) do
    NF.clip(context.handle)
    refresh_status(context)
  end

  @spec clip_preserve(t()) :: t()
  def clip_preserve(context) do
    NF.clip_preserve(context.handle)
    refresh_status(context)
  end

  @spec clip_extents(t()) :: {Cairo.vec2(), Cairo.vec2()}
  def clip_extents(context) do
    NF.clip_extents(context.handle)
  end

  @spec in_clip?(t(), Cairo.vec2()) :: boolean()
  def in_clip?(context, pt) do
    NF.in_clip(context.handle, pt)
  end

  @spec reset_clip(t()) :: t()
  def reset_clip(context) do
    NF.reset_clip(context.handle)
    refresh_status(context)
  end

  @spec fill(t()) :: t()
  def fill(context) do
    NF.fill(context.handle)
    refresh_status(context)
  end

  @spec fill_preserve(t()) :: t()
  def fill_preserve(context) do
    NF.fill_preserve(context.handle)
    refresh_status(context)
  end

  @spec fill_extents(t()) :: {Cairo.vec2(), Cairo.vec2()}
  def fill_extents(context) do
    NF.fill_extents(context.handle)
  end

  @spec in_fill?(t(), Cairo.vec2()) :: boolean()
  def in_fill?(context, pt) do
    NF.in_fill(context.handle, pt)
  end

  @spec paint(t()) :: t()
  def paint(context) do
    NF.paint(context.handle)
    refresh_status(context)
  end

  @spec paint_with_alpha(t(), number()) :: t()
  def paint_with_alpha(context, alpha) do
    NF.paint_with_alpha(context.handle, alpha)
    refresh_status(context)
  end

  @spec stroke(t()) :: t()
  def stroke(context) do
    NF.stroke(context.handle)
    refresh_status(context)
  end

  @spec stroke_preserve(t()) :: t()
  def stroke_preserve(context) do
    NF.stroke_preserve(context.handle)
    refresh_status(context)
  end

  @spec stroke_extents(t()) :: {Cairo.vec2(), Cairo.vec2()}
  def stroke_extents(context) do
    NF.stroke_extents(context.handle)
  end

  @spec in_stroke?(t(), Cairo.vec2()) :: boolean()
  def in_stroke?(context, pt) do
    NF.in_stroke(context.handle, pt)
  end

  @spec refresh(%__MODULE__{handle: NF.cairo_handle(), target: Surface.t()}) :: t()
  defp refresh(%__MODULE__{handle: handle, target: target} = context) do
    %__MODULE__{
      context
      | status: NF.status(handle),
        target: Surface.refresh(target),
        antialias: NF.get_antialias(handle),
        dash: NF.get_dash(handle),
        fill_rule: NF.get_fill_rule(handle),
        line_cap: NF.get_line_cap(handle),
        line_join: NF.get_line_join(handle),
        line_width: NF.get_line_width(handle),
        miter_limit: NF.get_miter_limit(handle),
        tolerance: NF.get_tolerance(handle)
    }
  end

  @spec refresh_status(%__MODULE__{handle: NF.cairo_handle()}) :: t()
  def refresh_status(%__MODULE__{handle: handle} = context) do
    %__MODULE__{context | status: NF.status(handle)}
  end
end
