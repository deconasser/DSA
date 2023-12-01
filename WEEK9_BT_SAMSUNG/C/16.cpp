Prim's Algorithm
Khởi tạo: Thay vì bắt đầu từ một đỉnh ngẫu nhiên, chúng ta có thể bắt đầu từ tất cả các đỉnh và chọn một đỉnh bất kỳ làm đỉnh xuất phát.

Lặp lại cho đến khi tất cả các đỉnh được duyệt qua:

Tại mỗi bước, chọn cạnh có trọng số nhỏ nhất kết nối một đỉnh thuộc cây đã tạo và một đỉnh nằm ngoài cây. Nếu có nhiều đỉnh nằm ngoài cây, chọn đỉnh có trọng số nhỏ nhất.
Cập nhật cây đã tạo bằng cách thêm đỉnh và cạnh mới đã chọn.
Kiểm tra kết thúc: Dừng khi tất cả các đỉnh đã được duyệt qua.

Kruskal's Algorithm
Sắp xếp cạnh: Sắp xếp tất cả các cạnh theo trọng số tăng dần.

Lặp lại cho đến khi tất cả các đỉnh được duyệt qua:

Chọn cạnh có trọng số nhỏ nhất. Nếu cạnh đã chọn tạo chu trình với các cạnh đã chọn trước đó, bỏ qua cạnh đó.
Ngược lại, thêm cạnh đã chọn vào cây đã tạo.
Kiểm tra kết thúc: Dừng khi tất cả các đỉnh đã được duyệt qua.