// Last updated: 20/07/2026, 10:38:27
object Solution {
    def limitOccurrences(nums: Array[Int], k: Int): Array[Int] = {
        var i = 0
        for (n <- nums) {
            if (i < k || n != nums(i - k)) {
                nums(i) = n
                i += 1
            }
        }
        nums.take(i)
    }
}