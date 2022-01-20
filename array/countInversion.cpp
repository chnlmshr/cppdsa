long long int cinv = 0;

void merge(long long arr[], long long l, long long m, long long r)
{
  long long n1 = m - l + 1, n2 = r - m;
  long long ar1[n1], ar2[n2];
  for (long long i = 0; i < n1; i++)
    ar1[i] = arr[i + l];
  for (long long i = 0; i < n2; i++)
    ar2[i] = arr[i + m + 1];
  long long i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (ar1[i] <= ar2[j])
      arr[k++] = ar1[i++];
    else
    {
      cinv += n1 - i;
      arr[k++] = ar2[j++];
    }
  }
  while (i < n1)
    arr[k++] = ar1[i++];
  while (j < n2)
    arr[k++] = ar2[j++];
}

void mergeSort(long long arr[], long long l, long long r)
{
  if (l < r)
  {
    long long m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

long long int inversionCount(long long arr[], long long n)
{
  cinv = 0;
  mergeSort(arr, 0, n - 1);
  return cinv;
}