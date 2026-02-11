function maxResult(nums: number[], k: number): number {
    
    let sum = 0

    for (let i = 1; i < nums.length; i++) {
        const jumpOptions = nums.slice(i, Math.min(nums.length - 1, i + k))
        sum += Math.max(...jumpOptions)
        i += jumpOptions.indexOf(Math.max(...jumpOptions))
        console.log(nums[i], sum)
        if (sum === Number.NEGATIVE_INFINITY) return sum
    }

    return sum
};

console.log(maxResult([1,-1,-2,4,-7,3], 2)) // 7