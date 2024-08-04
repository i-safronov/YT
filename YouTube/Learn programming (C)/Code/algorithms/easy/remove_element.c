int removeElement(int *nums, int numsSize, int val)
{
    int unique = 0, last_idx = numsSize - 1;

    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] == val)
        {
            for (int j = last_idx; j >= 0; --j)
            {
                if (nums[j] != val)
                {
                    nums[i] = nums[j];
                    last_idx = j - 1;
                    break;
                }
            }
        }
        else
        {
            ++unique;
        }
    }

    return unique;
}