//整个项目api的统一管理
import request from "./request";

//请求首页左侧表格的数据

export default {
  getTableData() {
    return request({
      url: "/api/home/getTableData",
      method: "get",
    });
  },
  getCountData() {
    return request({
      url: "/api/home/getCountData",
      method: "get",
    });
  },
  getChartData() {
    return request({
      url: "/api/home/getChartData",
      method: "get",
    });
  },
  getUserData(data) {
    return request({
      url: "http://localhost:6699/userInfo",
      method: "get",
      data,
    });
  },
  deleteUser(data) {
    return request({
      url: "/user/deleteUser",
      method: "get",
      data,
    });
  },
  addUser(data) {
    return request({
      url: "/userInfo/addUser",
      method: "post",
      data,
    });
  },
  editUser(data) {
    return request({
      url: "/user/editUser",
      method: "post",
      data,
    });
  },
  getMenu(params) {
    return request({
      url: "/permission/getMenu",
      method: "post",
      data: params,
    });
  },
};
