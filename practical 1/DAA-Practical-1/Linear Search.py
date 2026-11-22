
def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1

nums = [10, 50, 30, 70, 80, 20, 40]
target_val = 30

result = linear_search(nums, target_val)
if result != -1 :
    print(f"Linear Search: Element {target_val} found at index {result}")
else:
    print("Element not found")