defmodule Cairo.NativeFunctions.Macros do
  @moduledoc false

  defmacro defnif(call) do
    {name, args} = Macro.decompose_call(call)
    args2 = Enum.map(args, fn _ -> Macro.var(:_, __MODULE__) end)

    quote do
      def unquote(name)(unquote_splicing(args2)), do: raise "nif not loaded"
    end
  end
end

