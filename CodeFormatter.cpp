/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */




class Solution
{
public:
    int peakyFinders(MountainArray &mountainArr, int left, int right)
    {
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int binsearch(int target, MountainArray &mountainArr, int left, int right, bool isAsc)
    {
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (isAsc)
            {
                if (mountainArr.get(mid) > target)
                    left = mid + 1;
                else
                    right = mid + 1;
            }
            else
            {
                if (mountainArr.get(mid) > target)
                    right = mid + 1;
                else
                    left = mid + 1;
            }
        }
        return left;
    }

    
    int findInMountainArray(int target, MountainArray &mountainArr)
    {

        int size = mountainArr.length() - 1;
        int peak = peakyFinders(mountainArr, 0, size);
        int first = binsearch(target, mountainArr, 0, peak, true);
        if (mountainArr.get(first) != -1)
            return first;
        int second = binsearch(target, mountainArr, peak + 1, size, false);
        return second;
    }
};
