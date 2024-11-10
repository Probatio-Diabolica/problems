class NumMatrix:

    def __init__(self, matrix:list[list[int]]):
        ROWS,COLS = len(matrix) , len(matrix[0])
        self.sum_matrix=[[0]*(COLS+1) for r in range(ROWS+1)]

        for r in range (ROWS):
            prefix_sum=0
            for c in range (COLS) :
                prefix_sum+=matrix[r][c]
                above_this_position = self.sum_matrix[r][c+1]
                self.sum_matrix[r+1][c+1] = prefix_sum + above_this_position

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row1 ,col1,row2, col2 = row1+1,col1+1,row2+1,col2+1
        #area of the rectangle we want
        
        above = self.sum_matrix[row1-1][col2]
        left=self.sum_matrix[row2][col1-1]
        topLeft=self.sum_matrix[row1-1][col1-1]
        bottom_right = self.sum_matrix[row2][col2]

        return bottom_right - above -left+topLeft

