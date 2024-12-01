//! 5 - Hàm mã hóa và giải mã theo thuật toán Caesar

// Ma hoa: Ek (i) = (i + k) mod N
// Ma hoa: Dk (i) = (i - k) mod N

const VIETNAMESE_ALPHABET =
  "aAáÁạẠàÀảẢãÃăĂắẮặẶằẰẳẲẵẴâÂấẤậẬầẦẩẨẫẪbBcCdDđĐeEéÉẹẸèÈẻẺẽẼêÊếẾệỆềỀểỂễỄgGhHiIíÍịỊìÌỉỈĩĨkKlLmMnNoOóÓọỌòÒỏỎõÕôÔốỐộỘồỒổỔỗỖơƠớỚợỢờỜởỞỡỠpPqQrRsStTuUúÚụỤùÙủỦũŨưƯứỨựỰừỪửỬữỮvVxXyYýÝỵỴỳỲỷỶỹỸ"; // Z_178

const N = VIETNAMESE_ALPHABET.length;

const maHoa = (plaintext = "", key) => {
  if (typeof key !== "number") {
    throw new Error("Tham số đầu vào không hợp lệ");
  }

  plaintext = plaintext.trim();

  let ciphertext = "";

  for (let i = 0; i < plaintext.length; i++) {
    const index = VIETNAMESE_ALPHABET.indexOf(plaintext[i]);
    if (index === -1) {
      ciphertext += plaintext[i];
    } else {
      const newIndex = (index + key) % N;
      ciphertext += VIETNAMESE_ALPHABET[newIndex];
    }
  }

  return ciphertext;
};

const giaMa = (ciphertext = "", key) => {
  if (typeof key !== "number") {
    throw new Error("Tham số đầu vào không hợp lệ");
  }

  ciphertext = ciphertext.trim();

  let plaintext = "";

  for (let i = 0; i < ciphertext.length; i++) {
    const index = VIETNAMESE_ALPHABET.indexOf(ciphertext[i]);
    if (index === -1) {
      plaintext += ciphertext[i];
    } else {
      const newIndex = (index - key) % N;
      plaintext += VIETNAMESE_ALPHABET[newIndex];
    }
  }

  return plaintext;
};

const p_text = "ĐẠI HỌC CÔNG NGHIỆP HÀ NỘI";
const key = 3;

const c_text = maHoa(p_text, key);

console.log(c_text);

console.log(giaMa(c_text, key));
