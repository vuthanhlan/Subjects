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

//! 7 - Hàm mã hóa và giải mã theo thuật toán Affine
const sinhKhoaK_Affine = () => {
  const b = sinhSoNguyenToNgauNhien();
  let a = sinhSoNguyenToNgauNhien();

  while (!kiemTra2soNTCungNhau(a, N)) {
    a = sinhSoNguyenToNgauNhien();
  }

  // console.log("kiemTra2soNTCungNhau(a, N) :>> ", kiemTra2soNTCungNhau(a, N));

  console.log("sinhKhoaK_Affine: K = {a,b} = ", { a, b });

  return { a, b };
};

const maHoaAffine = (plaintext = "", a, b) => {
  if (typeof a !== "number" || typeof b !== "number") {
    throw new Error("Tham số đầu vào không hợp lệ");
  }

  plaintext = plaintext.trim();

  let ciphertext = "";

  for (let i = 0; i < plaintext.length; i++) {
    const index = VIETNAMESE_ALPHABET.indexOf(plaintext[i]);
    if (index === -1) {
      ciphertext += plaintext[i];
    } else {
      const newIndex = (a * index + b) % N;
      ciphertext += VIETNAMESE_ALPHABET[newIndex];
    }
  }

  return ciphertext;
};

const giaMaAffine = (ciphertext = "", a, b) => {
  if (typeof a !== "number" || typeof b !== "number" || a === 0 || b === 0) {
    throw new Error("Tham số đầu vào không hợp lệ");
  }

  ciphertext = ciphertext.trim();
  let plaintext = "";

  const phanTuNghichDaoA = phanTuNghichDao(a, N);

  for (let i = 0; i < ciphertext.length; i++) {
    const index = VIETNAMESE_ALPHABET.indexOf(ciphertext[i]);
    if (index === -1) {
      plaintext += ciphertext[i];
    } else {
      let newIndex = (index - b) * phanTuNghichDaoA;

      //
      while (newIndex < 0) {
        newIndex += N;
      }
      newIndex %= N;
      plaintext += VIETNAMESE_ALPHABET[newIndex];
    }
  }
  return plaintext;
};

console.log("=== Mã hóa ===");

const chuoiCanMaHoaAffine = "Dương Văn Dũng, Bắc Giang, Việt Nam";

// Tạo khóa K = {a,b} thoa man gcd(a, N) = 1, với N = 178
const { a, b } = sinhKhoaK_Affine();

const c1 = maHoaAffine(chuoiCanMaHoaAffine, a, b);
console.log(`maHoaAffine(${chuoiCanMaHoaAffine}, ${a}, ${b}) :: `, c1);

console.log("\n=== Giải mã ===");

const p1 = giaMaAffine(c1, a, b);
console.log(`giaMaAffine(${c1}, ${a}, ${b}) :: `, p1);
