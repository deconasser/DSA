Một thuật toán thời gian tuyến tính tính thành phần liên thông mạnh chứa một đỉnh v cho trước là thuật toán Kosaraju. Thuật toán này có các bước như sau:

Bước 1: Chạy duyệt theo chiều sâu (DFS) từ đỉnh v trên đồ thị ban đầu G, lưu lại thứ tự kết thúc duyệt các đỉnh vào một ngăn xếp S.
Bước 2: Tạo đồ thị nghịch đảo G’ của G, tức là đảo ngược hướng của tất cả các cạnh trên G.
Bước 3: Lấy ra lần lượt các đỉnh từ ngăn xếp S, chạy DFS từ mỗi đỉnh trên đồ thị G’, lưu lại các đỉnh đến được vào một tập hợp T. Tập hợp T chính là thành phần liên thông mạnh chứa đỉnh v.
Độ phức tạp thời gian của thuật toán này là O(n + m), trong đó n là số đỉnh và m là số cạnh của đồ thị, vì mỗi bước chỉ cần duyệt qua tất cả các đỉnh và cạnh một lần.

Dựa trên thuật toán Kosaraju, ta có thể mô tả một thuật toán thời gian bậc hai đơn giản để tính các thành phần liên thông mạnh của một đồ thị có hướng như sau:

Bước 1: Chọn một đỉnh bất kỳ trên đồ thị G, gọi là u, và áp dụng thuật toán Kosaraju để tìm thành phần liên thông mạnh chứa u, gọi là C. Đánh dấu các đỉnh thuộc C là đã thăm và coi chúng như một đỉnh duy nhất trên đồ thị.
Bước 2: Lặp lại bước 1 cho đến khi tất cả các đỉnh trên đồ thị đều được thăm. Mỗi lần lặp, ta sẽ tìm được một thành phần liên thông mạnh khác nhau.
Độ phức tạp thời gian của thuật toán này là O(n * (n + m)), trong đó n là số đỉnh và m là số cạnh của đồ thị, vì mỗi lần lặp, ta cần thực hiện thuật toán Kosaraju với độ phức tạp O(n + m), và số lần lặp không vượt quá n.