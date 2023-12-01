Sắp xếp tất cả các cạnh theo thứ tự tăng dần của trọng số.
Sử dụng thuật toán Union-Find để theo dõi các thành phần liên thông và quản lý cây bao trùm nhỏ nhất.
Duyệt qua các cạnh theo thứ tự tăng dần:

Bắt đầu với cây bao trùm nhỏ nhất được tạo bởi các cạnh có trọng số thấp nhất.
Duyệt qua từng cạnh, thêm cạnh đó vào cây bao trùm nếu nó không tạo chu trình.
Nếu cạnh đó tạo chu trình, ta cần kiểm tra xem cạnh đó có phải là cạnh khó không.
Kiểm tra cạnh khó bằng Online LCA:

Để kiểm tra xem cạnh có phải là cạnh khó hay không, chúng ta sử dụng kỹ thuật Online LCA.
Lưu trữ mỗi thành phần liên thông trong một cấu trúc dữ liệu Disjoint Set Union (DSU) để dễ dàng kiểm tra Lowest Common Ancestor (LCA) của hai đỉnh trong mỗi thành phần.
Khi một cạnh được thêm vào cây bao trùm, kiểm tra LCA của hai đỉnh của cạnh đó.
Nếu LCA của hai đỉnh không thay đổi so với trạng thái trước khi thêm cạnh, thì cạnh đó không làm tăng trọng số cây bao trùm min và là một cạnh khó.