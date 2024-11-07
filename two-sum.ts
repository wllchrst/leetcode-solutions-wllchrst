// 1 2 3 4, target = 6
// Map

function twoSum(nums: number[], target: number): number[] {
  const answer: number[] = [];
  const map = new Map<number, number>();

  nums.forEach((value, index) => {
    map.set(value, index);
  });

  for (let i = 0; i < nums.length; i++) {
    const findValue = target - nums[i];
    const find = map.get(findValue);

    if(find == i) continue;

    if (find != undefined) {
      answer.push(i, find);
      return answer;
    }
  }

  return [];
}

const answer = twoSum([2, 7, 11, 15], 9);

console.log(answer);
