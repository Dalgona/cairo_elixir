defmodule Cairo.NativeFunctions.Macros do
  @moduledoc false

  @spec defnif(Macro.t()) :: Macro.t()
  defmacro defnif(spec) do
    {:"::", _, [call, return_type]} = spec
    {nif_name, _, args} = call

    dummy_args =
      Enum.map(args, fn {:"::", _, [{var, _, _}, _type]} ->
        Macro.var(:"_#{var}", __MODULE__)
      end)

    quote do
      @spec unquote(nif_name)(unquote_splicing(args)) :: unquote(return_type)
      def unquote(nif_name)(unquote_splicing(dummy_args)) do
        :erlang.nif_error("NIF is not loaded")
      end
    end
  end
end
