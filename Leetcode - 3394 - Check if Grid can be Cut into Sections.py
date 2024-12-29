class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        ans = False

        # Check Vertical
        rectangles = sorted(rectangles, key = lambda x : x[0])
        amount_vertical = 0

        current_right_side = rectangles[0][2]
        for rec in rectangles: 
            x_left_up = rec[0]
            x_right_down = rec[2]

            if (x_left_up >= current_right_side): 
                amount_vertical += 1
                current_right_side = x_right_down
            else: 
                current_right_side = max(current_right_side, x_right_down)
        print(amount_vertical)
        ans |= (amount_vertical >= 2)

        # Check Horizontal
        rectangles = sorted(rectangles, key = lambda x : x[1])
        amount_horizontal = 0

        current_down_side = rectangles[0][3]
        for rec in rectangles: 
            y_left_up = rec[1]
            y_right_down = rec[3]

            if (y_left_up >= current_down_side): 
                amount_horizontal += 1
                current_down_side = y_right_down
            else: 
                current_down_side = max(current_down_side, y_right_down)
        ans |= (amount_horizontal >= 2)
        print(amount_horizontal)

        return ans
        