defmodule Solution do
  @spec is_anagram(s :: String.t(), t :: String.t()) :: boolean
  def is_anagram(s, t) do
    sort_string(s) == sort_string(t)
  end

  defp sort_string(str) do
    str
    |> String.graphemes()
    |> Enum.sort()
  end
end
