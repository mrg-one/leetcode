

#define mod (int)1e9 + 7

int countPermutations(int *complexity, int complexitySize)
{

  int min = complexity[1], i;
  long long count = 1;

  for (i = 1; i < complexitySize; ++i)
    if (complexity[i] < min)
      min = complexity[i];

  if (complexity[0] >= min)
    return 0;

  for (i = 1; i < complexitySize; ++i)
  {
    count *= i;
    if (count >= mod)
      count %= mod;
  }

  return count;
}
