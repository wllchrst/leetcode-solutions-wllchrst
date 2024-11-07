function containsDuplicate(nums: number[]): boolean {
  const map = new Map<number, boolean>();
  const length = nums.length;

  for (let i = 0; i < length; i++) {
    const currentNumber = nums[i];
    const findNumber = map.get(currentNumber);
    if (findNumber != undefined) return true;

    map.set(currentNumber, true);
  }
  return false;
}
