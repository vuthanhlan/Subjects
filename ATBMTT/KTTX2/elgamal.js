// import {
//   VIETNAMESE_ALPHABET,
//   sinhSoNgauNhien,
//   sinhSoNguyenToNgauNhien,
// } from "./helper.js";
// import a_mu_b_mod_n from "./a_mu_b_mod_n.js";
// import phanTuNghichDao from "./phanTuNghichDao.js";

const VIETNAMESE_ALPHABET =
  "aAáÁạẠàÀảẢãÃăĂắẮặẶằẰẳẲẵẴâÂấẤậẬầẦẩẨẫẪbBcCdDđĐeEéÉẹẸèÈẻẺẽẼêÊếẾệỆềỀểỂễỄgGhHiIíÍịỊìÌỉỈĩĨkKlLmMnNoOóÓọỌòÒỏỎõÕôÔốỐộỘồỒổỔỗỖơƠớỚợỢờỜởỞỡỠpPqQrRsStTuUúÚụỤùÙủỦũŨưƯứỨựỰừỪửỬữỮvVxXyYýÝỵỴỳỲỷỶỹỸ";
const N = VIETNAMESE_ALPHABET.length;
function bin2dec(binary) {
  // number
  let decimal = 0;
  let i = 0;
  while (binary !== 0) {
    const dec = binary % 10;
    decimal += dec * Math.pow(2, i);
    binary = Math.floor(binary / 10);
    i++;
  }
  return decimal; // number
}

function binaryToDecimal(binaryNumber) {
  // string
  let decimalNumber = 0;
  let base = 1; // Base bắt đầu từ 2^0 = 1

  // Lặp qua từng bit của số nhị phân, bắt đầu từ phải sang trái
  for (let i = binaryNumber.length - 1; i >= 0; i--) {
    // Nếu bit là 1, thì cộng vào kết quả
    if (binaryNumber[i] === "1") {
      decimalNumber += base;
    }
    // Di chuyển sang bit tiếp theo bằng cách nhân cơ số lên 2
    base *= 2;
  }

  return decimalNumber; // number
}

function he10sang2(number) {
  // number
  if (number === 0) {
    return "0";
  }

  let binary = "";

  while (number > 0) {
    binary = (number % 2) + binary;
    number = Math.floor(number / 2);
  }

  // return Number(binary);
  return binary; // string
}

//! 6 - Hàm tạo ra 2 số nguyên tố khác nhau có 6 chữ số
const ktraSoNguyenTo = (number) => {
  if (typeof number !== "number" || number !== Math.floor(number)) {
    throw new Error("Tham số đầu vào không hợp lệ");
  }
  for (let i = 2; i <= Math.floor(Math.sqrt(number)); i++) {
    if (number % i === 0) return false;
  }

  return number >= 2;
};

const gcd = (a, b) => {
  if (typeof a !== "number" || typeof b !== "number") {
    throw new Error("Tham số phải là số");
  }
  if (b === 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
};

const kiemTra2soNTCungNhau = (a, b) => {
  return gcd(a, b) === 1;
};

const sinhSoNguyenToNgauNhien = () => {
  let min = 1000;
  let max = 9999;
  let randomNumber = Math.floor(Math.random() * (max - min + 1)) + min;
  while (!ktraSoNguyenTo(randomNumber)) {
    randomNumber = Math.floor(Math.random() * (max - min + 1)) + min;
  }
  return randomNumber; // number
};

const sinhSoNgauNhien = () => {
  let min = 2;
  let max = 99;
  let randomNumber = Math.floor(Math.random() * (max - min + 1)) + min;

  return randomNumber; // number
};

//! 3 - Hàm tính a mũ -1 mod b (Tìm phần tử nghịch đảo)
const phanTuNghichDao = (a, b) => {
  if (
    typeof a !== "number" ||
    typeof b !== "number" ||
    !kiemTra2soNTCungNhau(a, b)
  ) {
    throw new Error(
      "Tham số đầu vào không hợp lệ, không thể tìm phần tử nghịch đảo"
    );
  }

  let r_i_tru_2 = b;
  let r_i_tru_1 = a;

  let x_i_tru_2 = 0;
  let x_i_tru_1 = 1;

  for (let i = 1; r_i_tru_1 !== 1; i++) {
    let q = Math.floor(r_i_tru_2 / r_i_tru_1);
    // console.log("r_i_tru_2 | r_i_tru_1 :: ", r_i_tru_2, r_i_tru_1);

    let tmp_r = r_i_tru_1;
    r_i_tru_1 = r_i_tru_2 - q * r_i_tru_1;
    r_i_tru_2 = tmp_r;

    let tmp_x = x_i_tru_1;
    x_i_tru_1 = x_i_tru_2 - q * x_i_tru_1;
    x_i_tru_2 = tmp_x;
  }

  while (x_i_tru_1 < 0) {
    x_i_tru_1 += b;
  }

  return x_i_tru_1;
};

const a_mu_b_mod_n = (a, b, n) => {
  if (typeof a !== "number" || typeof b !== "number" || typeof n !== "number") {
    throw new Error("Tham số đầu vào không hợp lệ");
  }
  // console.log(`${a}^${b} mod ${n} = `);

  if (b === n) {
    return a % n;
  }

  const binaryArray = he10sang2(b).split("");

  let f = 1;
  for (let i = 0; i < binaryArray.length; i++) {
    f = (f * f) % n;

    if (binaryArray[i] === "1") {
      f = (f * a) % n;
    }
  }

  return f; // number
};

const sinhKhoa = () => {
  const p = sinhSoNguyenToNgauNhien();
  const a = sinhSoNgauNhien();
  const x = sinhSoNgauNhien();

  const y = a_mu_b_mod_n(a, x, p);

  console.log("\n1. Khoa ca nhan :>> ", { p, a, x });
  console.log("2. Khoa cong khai :>> ", { p, a, y });

  return { privateKey: { p, a, x }, publicKey: { p, a, y } };
};

const maHoaEl = (M, { p, a, y }) => {
  if (typeof M === "string") {
    let C_array = [];

    for (let i = 0; i < M.length; i++) {
      let k = sinhSoNgauNhien();

      while (k < 1 || k > p - 1) {
        k = sinhSoNgauNhien();
      }
      const K = a_mu_b_mod_n(y, k, p);

      const C_1 = a_mu_b_mod_n(a, k, p);

      let M_index = VIETNAMESE_ALPHABET.indexOf(M[i]);

      let C_2 = ((K % p) * (M_index % p)) % p;
      if (C_2 < 0) C_2 = p + C_2;

      C_array.push({ C_1, C_2 });
    }

    return C_array;
  }

  let k = sinhSoNgauNhien();
  while (k < 1 || k > p - 1) {
    k = sinhSoNgauNhien();
  }

  // console.log("\nk :>> ", k);

  const K = a_mu_b_mod_n(y, k, p);

  const C_1 = a_mu_b_mod_n(a, k, p);

  let C_2 = ((K % p) * (M % p)) % p;

  return { C_1, C_2 };
};

const giaiMaEl = ({ C_1, C_2 }, { p, a, x }) => {
  const K = a_mu_b_mod_n(C_1, x, p);
  const tmp = phanTuNghichDao(K, p);

  const m = ((C_2 % p) * (tmp % p)) % p;

  return m;
};

const giaiMaElString = (C_array, { p, a, x }) => {
  let plaintext = "";

  for (let i = 0; i < C_array.length; i++) {
    const K = a_mu_b_mod_n(C_array[i].C_1, x, p);

    const tmp = phanTuNghichDao(K, p);

    const m = ((C_array[i].C_2 % p) * (tmp % p)) % p;

    if (!VIETNAMESE_ALPHABET[m]) {
      plaintext += " ";
      continue;
    }
    plaintext += VIETNAMESE_ALPHABET[m];
  }

  return plaintext;
};

const thongDiepM = 13;

const { privateKey, publicKey } = sinhKhoa();

const C = maHoaEl(thongDiepM, publicKey);

console.log("\n3. Thông điệp: ", thongDiepM);
console.log("\nBan ma:: ", C);
console.log("Ban giai ma:: ", giaiMaEl(C, privateKey));

//!
const thongDiepString = "Dương Văn Dũng";

// const { privateKey, publicKey } = sinhKhoa();

const C_string_encrypt = maHoaEl(thongDiepString, publicKey);

console.log("\n4. Thông điệp: ", thongDiepString);
console.log("\nBan ma:: ", C_string_encrypt);

console.log("Ban giai ma:: ", giaiMaElString(C_string_encrypt, privateKey));
