Khởi tạo: Chọn một đỉnh bất kỳ làm đỉnh xuất phát cho cây bao trùm.

Tạo Heap Ưu Tiên (Priority Queue): Đưa tất cả các cạnh từ tập cạnh S vào một heap ưu tiên, sắp xếp theo trọng số.

Lặp Lại:

Trong khi cây bao trùm chưa chứa tất cả các đỉnh:
Nếu heap ưu tiên không rỗng:
Lấy cạnh có trọng số nhỏ nhất từ heap.
Kiểm tra xem việc thêm cạnh đó vào cây bao trùm có tạo chu trình hay không:
Nếu không tạo chu trình, thêm cạnh đó vào cây bao trùm.
Nếu tạo chu trình, bỏ qua cạnh đó.
Kết Thúc:

Khi cây bao trùm chứa tất cả các đỉnh, thuật toán kết thúc.