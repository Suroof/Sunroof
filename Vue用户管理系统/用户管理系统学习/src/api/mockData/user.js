import Mock from "mockjs";

// 假设url是从某个地方传入的，这里直接作为参数
function param2obj(url) {
  const search = url.split("?")[1];
  if (!search) {
    return {};
  }
  return JSON.parse(
    '{"' +
      decodeURIComponent(search)
        .replace(/"/g, '\\"')
        .replace(/&/g, '","')
        .replace(/=/g, '":"') +
      '"}'
  );
}

let List = [];
const count = 200; // 模拟200条用户数据
for (let i = 0; i < count; i++) {
  List.push(
    Mock.mock({
      id: Mock.Random.guid(),
      name: Mock.Random.cname(),
      addr: Mock.mock("@county(true)"),
      "age|18-60": 1,
      birth: Mock.Random.date(),
      "sex|0-1": 1,
    })
  );
}

export default {
  // 获取列表，要带参数 name, page, limit; name 可以不填，page, limit 有默认值
  getUserList: (config) => {
    const { name, page = 1, limit = 10 } = param2obj(config.url);

    const mockList = List.filter((user) => {
      // 如果name存在，则根据name筛选数据
      if (name && user.name.indexOf(name) === -1) return false;
      return true;
    });

    // 分页
    const startIndex = (page - 1) * limit;
    const endIndex = startIndex + limit;
    const pageList = mockList.slice(startIndex, endIndex);

    return {
      code: 200,
      data: {
        list: pageList,
        count: mockList.length, // 数据总条数要返回
      },
    };
  },

  // 删除用户的方法
  deleteUser: (config) => {
    const { id } = param2obj(config.url);
    if (!id) {
      return {
        code: -999,
        message: "参数不正确",
      };
    } else {
      List = List.filter((u) => u.id !== id);
      return {
        code: 200,
        message: "删除成功",
      };
    }
  },
  // 增加用户
  createUser: (config) => {
    try {
      // 使用JSON.parse解析config.body中的JSON字符串
      const { name, addr, age, birth, sex } = JSON.parse(config.body);
      List.unshift({
        id: Mock.Random.guid(),
        name: name,
        addr: addr,
        age: age,
        birth: birth,
        sex: sex,
      });
      return {
        code: 200,
        data: {
          message: "添加成功",
        },
      };
    } catch (error) {
      return {
        code: 400,
        data: {
          message: "解析错误: " + error.message,
        },
      };
    }
  },
  //编辑用户
  updateUser: (config) => {
    const { id, name, addr, age, birth, sex } = JSON.parse(config.body);
    const sex_num = parseInt(sex);
    List.some((u) => {
      if (u.id === id) {
        u.name = name;
        u.addr = addr;
        u.age = age;
        u.birth = birth;
        u.sex = sex_num;
        return true;
      }
    });
    return {
      code: 200,
      data: {
        message: "编辑成功",
      },
    };
  },
};
